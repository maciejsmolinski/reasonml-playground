let component = ReasonReact.statelessComponent("Subcategory");

let make = (~name, ~resources, _children) => {
  ...component,
  render: _self =>
    <div className="box">
      <div className="content">
        <span
          className="is-uppercase has-text-weight-light is-size-7 has-text-grey">
          (ReasonReact.string(name))
        </span>
        <ul>
          (
            resources
            |> Array.map((resource: Data.resource) =>
                 <li key=resource##title>
                   <a
                     href=resource##url
                     target="_blank"
                     rel="noopener noreferrer"
                     className="has-text-grey-dark">
                     (ReasonReact.string(resource##title))
                   </a>
                 </li>
               )
            |> ReasonReact.array
          )
        </ul>
      </div>
    </div>,
};