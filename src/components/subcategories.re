let component = ReasonReact.statelessComponent("Subcategories");

let make = (~data, _children) => {
  ...component,
  render: _self => {
    let toSubcategory = item =>
      <Subcategory name=item##name key=item##name resources=item##resources />;
    data |> Array.map(toSubcategory) |> ReasonReact.array;
  },
};