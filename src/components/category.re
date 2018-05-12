let component = ReasonReact.statelessComponent("Category");

let make = (~name, _children) => {
  ...component,
  render: _self =>
    <span className="categories__item tag is-dark">
      (ReasonReact.string(name))
    </span>,
};