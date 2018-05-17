type loadingAction('a) =
  | Load
  | Update('a)
  | Failed;

type remoteData('a) =
  | NotAsked
  | Loading
  | Failure(string)
  | Success('a);

type action =
  | Category(loadingAction(array(Data.category)))
  | Subcategory(loadingAction(array(Data.subcategory)));

type state = {
  categories: remoteData(array(Data.category)),
  subcategories: remoteData(array(Data.subcategory)),
};

let component = ReasonReact.reducerComponent("Application");

let make = _children => {
  ...component,
  didMount: _self => {
    _self.send(Category(Load));
    Js.Promise.(
      Api.getCategories()
      |> then_(categories =>
           _self.send(Category(Update(categories))) |> resolve
         )
      |> catch((_) => _self.send(Category(Failed)) |> resolve)
      |> ignore
    );
  },
  initialState: () => {categories: NotAsked, subcategories: NotAsked},
  reducer: (action, state) =>
    switch (action) {
    | Category(a) =>
      switch (a) {
      | Load => ReasonReact.Update({...state, categories: Loading})
      | Update(cs) => ReasonReact.Update({...state, categories: Success(cs)})
      | Failed =>
        ReasonReact.Update({
          ...state,
          categories: Failure("Failed to load categories"),
        })
      }
    | Subcategory(a) =>
      switch (a) {
      | Load => ReasonReact.Update({...state, subcategories: Loading})
      | Update(cs) =>
        ReasonReact.Update({...state, subcategories: Success(cs)})
      | Failed =>
        ReasonReact.Update({
          ...state,
          subcategories: Failure("Failed to load subcategories"),
        })
      }
    },
  render: _self => {
    let onSelected = category => {
      _self.send(Subcategory(Load));
      Js.Promise.(
        Api.getCategory(category)
        |> then_(data => {
             Js.log2(category, data);
             _self.send(Subcategory(Update(data)));
             resolve(data);
           })
        |> ignore
      );
    };
    <div className="section">
      <div className="container">
        <div className="columns">
          <div className="column">
            <div className="section">
              (
                switch (_self.state.subcategories) {
                | NotAsked => ReasonReact.null
                | Loading => ReasonReact.string("Loading subcategories...")
                | Failure(error) => ReasonReact.string(error)
                | Success(subcategories) =>
                  <Subcategories data=subcategories />
                }
              )
            </div>
          </div>
          <div className="column is-one-third">
            (
              switch (_self.state.categories) {
              | NotAsked => <div> (ReasonReact.string("...")) </div>
              | Loading => ReasonReact.string("Loading categories...")
              | Failure(error) => ReasonReact.string(error)
              | Success(categories) =>
                <Categories data=categories onSelected />
              }
            )
          </div>
        </div>
      </div>
    </div>;
  },
};