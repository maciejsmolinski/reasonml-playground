let component = ReasonReact.statelessComponent("Category");

let make = (~name, ~path, _children) => {
  ...component,
  render: _self =>
    <span className="categories__item tag is-rounded is-primary is-medium">
      (ReasonReact.string(name))
    </span>,
};