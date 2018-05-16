let component = ReasonReact.statelessComponent("Categories");

let make = (~data, ~onSelected, _children) => {
  ...component,
  render: _self => {
    let toCategory = item =>
      <Category name=item##name key=item##path path=item##path onSelected />;
    data |> Array.map(toCategory) |> ReasonReact.array;
  },
};