[@ocaml.ppx.context
  {
    tool_name: "migrate_driver",
    include_dirs: [],
    load_path: [],
    open_modules: [],
    for_package: None,
    debug: false,
    use_threads: false,
    use_vmthreads: false,
    recursive_types: false,
    principal: false,
    transparent_modules: false,
    unboxed_types: false,
    unsafe_string: false,
    cookies: [],
  }
];
module MyQuery' = {
  module Raw = {
    type t = {. "scalarsInput": string};
    type t_variables = {
      .
      "nullableString": Js.Nullable.t(string),
      "string": string,
      "nullableInt": Js.Nullable.t(int),
      "int": int,
      "nullableFloat": Js.Nullable.t(float),
      "float": float,
      "nullableBoolean": Js.Nullable.t(bool),
      "boolean": bool,
      "nullableID": Js.Nullable.t(string),
      "id": string,
    };
  };
  let query = "query ($nullableString: String, $string: String!, $nullableInt: Int, $int: Int!, $nullableFloat: Float, $float: Float!, $nullableBoolean: Boolean, $boolean: Boolean!, $nullableID: ID, $id: ID!)  {\nscalarsInput(arg: {nullableString: $nullableString, string: $string, nullableInt: $nullableInt, int: $int, nullableFloat: $nullableFloat, float: $float, nullableBoolean: $nullableBoolean, boolean: $boolean, nullableID: $nullableID, id: $id})  \n}\n";
  type t = {. "scalarsInput": string};
  type t_variables = {
    .
    "nullableString": option(string),
    "string": string,
    "nullableInt": option(int),
    "int": int,
    "nullableFloat": option(float),
    "float": float,
    "nullableBoolean": option(bool),
    "boolean": bool,
    "nullableID": option(string),
    "id": string,
  };
  let parse: Raw.t => t =
    value => {
      let scalarsInput = {
        let value = value##scalarsInput;
        value;
      };
      {"scalarsInput": scalarsInput};
    };
  let serialize: t => Raw.t =
    value => {
      let scalarsInput = {
        let value = value##scalarsInput;
        value;
      };
      {"scalarsInput": scalarsInput};
    };
  let serializeVariables: t_variables => Raw.t_variables =
    inp => {
      "nullableString":
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          inp##nullableString,
        ),
      "string": (a => a)(inp##string),
      "nullableInt":
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          inp##nullableInt,
        ),
      "int": (a => a)(inp##int),
      "nullableFloat":
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          inp##nullableFloat,
        ),
      "float": (a => a)(inp##float),
      "nullableBoolean":
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          inp##nullableBoolean,
        ),
      "boolean": (a => a)(inp##boolean),
      "nullableID":
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          inp##nullableID,
        ),
      "id": (a => a)(inp##id),
    };
  let make =
      (
        ~nullableString=?,
        ~string,
        ~nullableInt=?,
        ~int,
        ~nullableFloat=?,
        ~float,
        ~nullableBoolean=?,
        ~boolean,
        ~nullableID=?,
        ~id,
        (),
      ) => {
    "query": query,
    "variables":
      serializeVariables(
        {
          "nullableString": nullableString,
          "string": string,
          "nullableInt": nullableInt,
          "int": int,
          "nullableFloat": nullableFloat,
          "float": float,
          "nullableBoolean": nullableBoolean,
          "boolean": boolean,
          "nullableID": nullableID,
          "id": id,
        }: t_variables,
      ),
    "parse": parse,
  }
  and makeVariables =
      (
        ~nullableString=?,
        ~string,
        ~nullableInt=?,
        ~int,
        ~nullableFloat=?,
        ~float,
        ~nullableBoolean=?,
        ~boolean,
        ~nullableID=?,
        ~id,
        (),
      ) =>
    serializeVariables(
      {
        "nullableString": nullableString,
        "string": string,
        "nullableInt": nullableInt,
        "int": int,
        "nullableFloat": nullableFloat,
        "float": float,
        "nullableBoolean": nullableBoolean,
        "boolean": boolean,
        "nullableID": nullableID,
        "id": id,
      }: t_variables,
    );
  let makeWithVariables = variables => {
    "query": query,
    "variables": serializeVariables(variables),
    "parse": parse,
  };
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module MyQuery {
  // This is the stringified representation of your query, which gets sent to the server.
  let query: string;

  // This is the main type of the result you will get back.
  // You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  type t;

  // This function turns your raw result from the server into the reason/ocaml representation of that result.
  // Depending on your graphql client library, this process should happen automatically for you.
  let parse: Raw.t => t;

  // This function will prepare your data for sending it back to the server.
  // Depending on your graphql client library, this process should happen automatically for you.
  let serialize: t => Raw.t;

  // The definition tuple is primarily used to interact with client libraries.
  // The types are equivalent to: (parse, query, serialize).
  // Your client library will use these values to provide the properly parsed / serialized data for you.
  let definition: (
    Raw.t => t,
    string,
    t => Raw.t
  );

  // This is the representation of your raw result coming from the server.
  // It should not be necessary to access the types inside for normal use cases.
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
module MyQuery = {
  include MyQuery';
  module type Type = GraphQL_PPX.Query;
  let self: module Type = (module MyQuery');
};
