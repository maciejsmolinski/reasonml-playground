module Application = {
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
      Js.Promise.(
        Fetch.fetch(
          "https://rawgit.com/maciejsmolinski/learnings/master/README.md",
        )
        |> then_(Bs_fetch.Response.text)
        |> then_(text
             /* _self.send(Update @@ Data.extractCategories(text)) |> resolve */
             =>
               Data.extractCategories(text)
               |> (categories => _self.send(Update(categories)) |> resolve)
             )
        |> catch((_) => _self.send(Fail) |> resolve)
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
};

module App = {
  let init = () => {
    Document.addReasonApplicationContainer("reason-application");
    ReactDOMRe.renderToElementWithId(<Application />, "reason-application");
  };
};