let component = ReasonReact.statelessComponent("Categories");

let toCategory = name => <Category name key=name />;

let make = (~data, _children) => {
  ...component,
  render: _self => data |> Array.map(toCategory) |> ReasonReact.array,
};