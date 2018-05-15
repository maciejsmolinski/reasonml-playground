let component = ReasonReact.statelessComponent("Category");

let make = (~name, ~path, ~onSelected, _children) => {
  ...component,
  render: _self =>
    <span
      className="categories__item tag is-rounded is-primary is-medium is-clickable"
      onClick=((_) => onSelected(path))>
      (ReasonReact.string(name))
    </span>,
};