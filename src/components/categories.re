let component = ReasonReact.statelessComponent("Categories");

let make = (~data, _children) => {
  ...component,
  render: _self => {
    let toCategory = category =>
      <Category name=category##name key=category##path path=category##path />;
    data |> Array.map(toCategory) |> ReasonReact.array;
  },
};