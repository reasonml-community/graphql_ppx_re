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
    type t = {enumInput: string};
    type t_variables = {arg: string};
  };
  let query = "query ($arg: SampleField!)  {\nenumInput(arg: $arg)  \n}\n";
  type t = {enumInput: string};
  type t_variables = {arg: [ | `FIRST | `SECOND | `THIRD]};
  let parse: Raw.t => t =
    (value) => (
      {
        enumInput: {
          let value = (value: Raw.t).enumInput;
          value;
        },
      }: t
    );
  let serialize: t => Raw.t =
    (value) => (
      {
        let enumInput = {
          let value = (value: t).enumInput;
          value;
        };
        {enumInput: enumInput};
      }: Raw.t
    );
  let serializeVariables: t_variables => Raw.t_variables =
    inp => {
      arg:
        (
          a =>
            switch (a) {
            | `FIRST => "FIRST"
            | `SECOND => "SECOND"
            | `THIRD => "THIRD"
            }
        )(
          (inp: t_variables).arg,
        ),
    };
  let makeVariables = (~arg, ()) =>
    serializeVariables({arg: arg}: t_variables);
  module Z__INTERNAL = {
    type nonrec _graphql_arg_82;
    /**Variable **$arg** has the following graphql type:

```
SampleField {
  FIRST
  SECOND
  THIRD
}!
```*/
    let _graphql_arg_82: _graphql_arg_82 = Obj.magic(0);
    type nonrec _graphql_arg_77;
    /**Argument **arg** on field **enumInput** has the following graphql type:

```
SampleField {
  FIRST
  SECOND
  THIRD
}!
```*/
    let _graphql_arg_77: _graphql_arg_77 = Obj.magic(0);
    type root = t;
    type nonrec _graphql_SampleField_47;
    /**```
SampleField {
  FIRST
  SECOND
  THIRD
}
```*/
    let _graphql_SampleField_47: _graphql_SampleField_47 = Obj.magic(0);
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
