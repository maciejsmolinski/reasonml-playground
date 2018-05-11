module Dom = {
  let clear: unit => unit = [%bs.raw
    {|
    function () {
      typeof document !== 'undefined' && document.body && (document.body.innerHTML = "");
    }
  |}
  ];
  let append: string => unit = [%bs.raw
    {|
      function (content) {
        typeof document !== 'undefined' && document.body && (document.body.innerHTML = document.body.innerHTML + '<br>' + content);
      }
    |}
  ];
};

module Greeting = {
  let component = ReasonReact.statelessComponent("Greeting");
  let make = (~name, _children) => {
    ...component,
    render: _self =>
      <div>
        (ReasonReact.string("Hello "))
        <strong> (ReasonReact.string(name)) </strong>
        (ReasonReact.string("!"))
      </div>,
  };
};

let wrapper: string => unit =
  uniqueId => Dom.append({j|<div id="$uniqueId">$uniqueId</div>|j});

type position =
  | Left
  | Right;

let show: position => string =
  position =>
    switch (position) {
    | Left => "left"
    | Right => "right"
    };

let modules = [|
  (<Greeting name="User 1" />, Left),
  (<Greeting name="User 2" />, Right),
|];

Dom.clear();

modules
|> Array.map(((component, pos)) => {
     wrapper @@ show(pos);
     ReactDOMRe.renderToElementWithId(component, show(pos));
   });