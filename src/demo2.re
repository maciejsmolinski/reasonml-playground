type payload = {. "name": string};

/* var myAjaxLibrary = require('myAjaxLibrary'); */
[@bs.module "myAjaxLibrary"]
external sendQuery : payload => unit = "sendQuery";

/* var Ramda = require('ramda'); */
[@bs.module "ramda"] external add : (int, int) => int = "add";

let main = () => {
  /* Numbers */
  Js.log(23.0 -. 3.33);
  Js.log(10 / 3);
  Js.log(10.0 /. 3.0);
  Js.log([1, 2, 3]);
  let rest = [1, 2, 3];
  Js.log([1, 2, 3, ...rest]);
  {
    let abc = 1;
    Js.log(abc);
  };
  let message = "hello";
  print_endline(message); /* Prints "hello" */
  let message = {|
    long string with a slash \\
    |};
  let world = {js|世界|js};
  /* Interpolation */
  let helloWorld = {j|你好，$world|j};
  print_endline(message);
  print_endline(helloWorld);
  let char = "abc".[0];
  print_char(char);
  let abc = Some(10);
  let result =
    switch (abc) {
    | Some(_) => "value"
    | None => "empty"
    };
  print_string(result);
  print_newline();
  let ghi = [%bs.raw {| 'here is a string from javascript' |}];
  print_string(ghi);
  print_newline();
  let add: (int, int) => int = [%bs.raw "a + b"];
  sendQuery({"name": "Reason"});
  print_int(add(1, 2));
  ();
};

let () = {
  let xyz = "Hello World";
  print_string(xyz);
  print_newline();
};