let component = ReasonReact.statelessComponent("Category");

let make = (~name, ~path, ~onSelected, _children) => {
  ...component,
  render: _self =>
    <li onClick=((_) => onSelected(path))>
      <a> (ReasonReact.string(name)) </a>
    </li>,
};