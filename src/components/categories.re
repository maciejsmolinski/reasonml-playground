let component = ReasonReact.statelessComponent("Categories");

let make = (~data, ~onSelected, _children) => {
  ...component,
  render: _self => {
    let toCategory = category =>
      <Category
        name=category##name
        key=category##path
        path=category##path
        onSelected
      />;
    data |> Array.map(toCategory) |> ReasonReact.array;
  },
};