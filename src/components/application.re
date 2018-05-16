type action =
  | LoadingCategories
  | LoadingSubcategories
  | UpdateCategories(array(Data.category))
  | UpdateSubcategories(array(Data.subcategory))
  | FailedToLoadCategories
  | FailedToLoadSubcategories;

type remoteData('a) =
  | NotAsked
  | Loading
  | Failure(string)
  | Success('a);

type state = {
  categories: remoteData(array(Data.category)),
  subcategories: remoteData(array(Data.subcategory)),
};

let component = ReasonReact.reducerComponent("Application");

let make = _children => {
  ...component,
  didMount: _self => {
    _self.send(LoadingCategories);
    Js.Promise.(
      Api.getCategories()
      |> then_(categories =>
           _self.send(UpdateCategories(categories)) |> resolve
         )
      |> catch((_) => _self.send(FailedToLoadCategories) |> resolve)
      |> ignore
    );
  },
  initialState: () => {categories: NotAsked, subcategories: NotAsked},
  reducer: (action, state) =>
    switch (action) {
    | LoadingCategories => ReasonReact.Update({...state, categories: Loading})
    | UpdateCategories(cs) =>
      ReasonReact.Update({...state, categories: Success(cs)})
    | FailedToLoadCategories =>
      ReasonReact.Update({
        ...state,
        categories: Failure("Failed to load categories"),
      })
    | LoadingSubcategories =>
      ReasonReact.Update({...state, subcategories: Loading})
    | UpdateSubcategories(subcategories) =>
      ReasonReact.Update({...state, subcategories: Success(subcategories)})
    | FailedToLoadSubcategories =>
      ReasonReact.Update({
        ...state,
        categories: Failure("Failed to load subcategories"),
      })
    },
  render: _self => {
    let onSelected = category => {
      _self.send(LoadingSubcategories);
      Js.Promise.(
        Api.getCategory(category)
        |> then_(data => {
             Js.log2(category, data);
             _self.send(UpdateSubcategories(data));
             resolve(data);
           })
        |> ignore
      );
    };
    <div>
      <div className="categories">
        (
          switch (_self.state.categories) {
          | NotAsked => <div> (ReasonReact.string("...")) </div>
          | Loading => ReasonReact.string("Loading categories...")
          | Failure(error) => ReasonReact.string(error)
          | Success(categories) => <Categories data=categories onSelected />
          }
        )
      </div>
      <div className="categories">
        (
          switch (_self.state.subcategories) {
          | NotAsked => ReasonReact.null
          | Loading => ReasonReact.string("Loading subcategories...")
          | Failure(error) => ReasonReact.string(error)
          | Success(_) => ReasonReact.string("Subcategories")
          }
        )
      </div>
    </div>;
  },
};