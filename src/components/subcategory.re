let component = ReasonReact.statelessComponent("Subcategory");

let make = (~name, ~resources, _children) => {
  ...component,
  render: _self =>
    <div className="box">
      <div className="content">
        <h2 className="title is-5"> (ReasonReact.string(name)) </h2>
        <ul>
          (
            resources
            |> Array.map(resource =>
                 <li key=resource> (ReasonReact.string(resource)) </li>
               )
            |> ReasonReact.array
          )
        </ul>
      </div>
    </div>,
};