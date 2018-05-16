let component = ReasonReact.statelessComponent("Subcategory");

let make = (~name, ~resources, _children) => {
  ...component,
  render: _self =>
    <div className="content is-small">
      <h2> (ReasonReact.string(name)) </h2>
      <ul>
        (
          resources
          |> Array.map(resource =>
               <li key=resource> (ReasonReact.string(resource)) </li>
             )
          |> ReasonReact.array
        )
      </ul>
    </div>,
};