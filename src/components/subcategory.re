let component = ReasonReact.statelessComponent("Subcategory");

let make = (~name, ~resources, _children) => {
  ...component,
  render: _self =>
    <div className="subcategories__item">
      <span className="tag"> (ReasonReact.string(name)) </span>
      <br />
      (
        resources
        |> Array.map(resource =>
             <div key=resource> (ReasonReact.string(resource)) </div>
           )
        |> ReasonReact.array
      )
    </div>,
};