type action =
  | Load
  | Update(array(Data.category))
  | Fail;

type state =
  | NotAsked
  | Loading
  | Failure(string)
  | Success(array(Data.category));

let component = ReasonReact.reducerComponent("Application");

let make = _children => {
  ...component,
  didMount: _self => {
    _self.send(Load);
    Js.Promise.(
      Api.getCategories()
      |> then_(categories => _self.send(Update(categories)) |> resolve)
      |> catch((_) => _self.send(Fail) |> resolve)
      |> ignore
    );
  },
  initialState: () => NotAsked,
  reducer: (action, _) =>
    switch (action) {
    | Load => ReasonReact.Update(Loading)
    | Update(categories) => ReasonReact.Update(Success(categories))
    | Fail => ReasonReact.Update(Failure("Failed to load content"))
    },
  render: _self => {
    let onSelected = category =>
      ignore @@
      Js.Promise.(
        Api.getCategory(category)
        |> then_(data => {
             Js.log2(category, data);
             resolve(data);
           })
      );
    <div className="categories">
      (
        switch (_self.state) {
        | NotAsked => <div> (ReasonReact.string("...")) </div>
        | Loading => ReasonReact.string("Loading categories...")
        | Failure(error) => ReasonReact.string(error)
        | Success(categories) => <Categories data=categories onSelected />
        }
      )
    </div>;
  },
};