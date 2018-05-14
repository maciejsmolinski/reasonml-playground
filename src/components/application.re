type categories = array(string);

type action =
  | Load
  | Update(categories)
  | Fail;

type state =
  | NotAsked
  | Loading
  | Failure(string)
  | Success(categories);

let component = ReasonReact.reducerComponent("Application");

let make = _children => {
  ...component,
  didMount: _self => {
    _self.send(Load);
    ignore @@
    (
      Api.getCategories()
      |> Js.Promise.then_(categories =>
           _self.send(Update(categories)) |> Js.Promise.resolve
         )
      |> Js.Promise.catch((_) => _self.send(Fail) |> Js.Promise.resolve)
    );
  },
  initialState: () => NotAsked,
  reducer: (action, _) =>
    switch (action) {
    | Load => ReasonReact.Update(Loading)
    | Update(categories) => ReasonReact.Update(Success(categories))
    | Fail => ReasonReact.Update(Failure("Failed to load content"))
    },
  render: _self =>
    <div className="categories">
      (
        switch (_self.state) {
        | NotAsked => <div> (ReasonReact.string("...")) </div>
        | Loading => ReasonReact.string("Loading categories...")
        | Failure(error) => ReasonReact.string(error)
        | Success(categories) => <Categories data=categories />
        }
      )
    </div>,
};