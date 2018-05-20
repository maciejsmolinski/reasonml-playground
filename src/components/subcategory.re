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
            |> Array.map((resource: Data.resource) =>
                 <li key=resource##title>
                   <a
                     href=resource##url
                     target="_blank"
                     rel="noopener noreferrer">
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