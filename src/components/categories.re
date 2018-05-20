let component = ReasonReact.statelessComponent("Categories");

let make = (~data, ~onSelected, _children) => {
  ...component,
  render: _self => {
    let toCategory = (item: Data.category) =>
      <Category name=item##name key=item##path path=item##path onSelected />;
    <div className="box">
      <aside className="menu">
        <p className="menu-label"> (ReasonReact.string("Categories")) </p>
        <ul className="menu-list">
          (data |> Array.map(toCategory) |> ReasonReact.array)
        </ul>
      </aside>
    </div>;
  },
};