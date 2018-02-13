module Maybe = {
    type maybeT('a) =
      | Nothing
      | Just('a);
    let map = (func, v) =>
      switch v {
      | Nothing => Nothing
      | Just(a) => Just(func(a))
      };
    let ap = (func, v) => {
      switch v {
      | Nothing => Nothing
      | Just(a) => switch (func) {
      | Nothing => Nothing
      | Just(f) => Just(f(a))
      }
      }
    };
    let id = (v) => v;
    let maybe = (fallback, transform, v) =>
      switch v {
      | Nothing => fallback
      | Just(a) => transform(a)
      };
  };

  let value = Maybe.Nothing;

  let value' = Maybe.Just("value");

  let transform = (_) => "Mapped";

  let mapped = Maybe.map(transform, value);

  let mapped' = Maybe.map(transform, value');

  Js.log(Maybe.maybe("Nothing", Maybe.id, mapped));

  Js.log(Maybe.maybe("Nothing", Maybe.id, mapped'));

  Js.log(Maybe.ap(Maybe.Just(Maybe.id), Maybe.Just("string")));