let component = ReasonReact.statelessComponent("Categories");

let make = (~data, _children) => {
  ...component,
  render: _self => {
    let toCategory = name => <Category name key=name />;
    data |> Array.map(toCategory) |> ReasonReact.array;
  },
};