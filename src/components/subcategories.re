let component = ReasonReact.statelessComponent("Subcategories");

let make = (~data, _children) => {
  ...component,
  render: _self => {
    let toSubcategory = subcategory =>
      <Subcategory
        name=subcategory##name
        key=subcategory##name
        resources=subcategory##resources
      />;
    data |> Array.map(toSubcategory) |> ReasonReact.array;
  },
};