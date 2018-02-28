type payload = {. "name": string};

[@bs.module "myAjaxLibrary"]
external sendQuery : payload => unit = "sendQuery";

[@bs.module "ramda"] external add : (int, int) => int = "add";

type scoreType = int;

type horsePower = {
  power: int,
  metric: bool,
};

/* [@bs.val] external isStudent : string => bool = "isStudent"; */
/* let isSt = Js.Boolean.to_js_boolean(isStudent("abcs")); */
module School = {
  type person = {
    age: int,
    name: string,
  };
};

type person = {
  name: string,
  mutable age: int,
};

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
  /* let message = {
       let part1 = "hello";
       let part2 = "world";
       part1 ++ " " ++ part2;
     }; */
  let char = "abc".[0];
  print_char(char);
  /* let a = 1;
     let b = 2; */
  /* a + b;
     (a, b) => a + b;
     let score: int = 10;
     let myInt = (5: int) + (4: int);
     let drawCircle = () : unit => ();
     let def: option(int) = None; */
  let abc = Some(10);
  let result =
    switch (abc) {
    | Some(_) => "value"
    | None => "empty"
    };
  /* let x: scoreType = 10; */
  print_string(result);
  print_newline();
  let ghi = [%bs.raw {| 'here is a string from javascript' |}];
  print_string(ghi);
  print_newline();
  let add: (int, int) => int = [%bs.raw "a + b"];
  /* let me: School.person = {age: 20, name: "Big Reason"}; */
  /* let me = {School.age: 20, name: "Big Reason"}; */
  /* let meNextYear = {...me, age: me.age + 1}; */
  let baby = {name: "Baby Reason", age: 5};
  baby.age = baby.age + 1; /* alter `baby`. Happy birthday! */
  /* let metric = true; */
  /* let someHorsePower = {power: 10, metric}; */
  sendQuery({"name": "Reason"});
  /* let ras = [1, 2, 3]; */
  /* let rbs = [|1, 2, 3|]; */
  /* Array.append(rbs, rbs); */
  /* List.append(ras, ras); */
  print_int(add(1, 2));
  ();
};

let () = {
  let xyz = "Hello World";
  print_string(xyz);
  print_newline();
};