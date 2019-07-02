# [bs-react-trello](https://www.npmjs.com/package/bs-react-trello)

This is [Bucklescript](https://bucklescript.github.io/) bindings for [react-trello](https://github.com/rcdexta/react-trello).

# Install
```
yarn add bs-react-trello
```

# Setup

Add bs-react-trello to `bs-depenencies` in your `bsconfig.json`!

```js
{
  /* ... */
  "bs-dependencies": [
    "bs-react-trello"
  ],
  /* ... */
}
```

# Example

```reason
let data = [|
  ReactTrello.Lane.t(
    ~id="title1",
    ~label="title1 label",
    ~addCardLink=React.string("title 1 addCardLink"),
    ~cards=[|
      ReactTrello.Card.t(
        ~id="t1 card1",
        ~title="t1 title1",
        ~description="t1 description",
        (),
      ),
      ReactTrello.Card.t(
        ~id="t2 card1",
        ~title="t2 title1",
        ~description="t2 description",
        (),
      ),
    |],
    (),
  ),
  ReactTrello.Lane.t(
    ~id="title2",
    ~label="title2 label",
    ~addCardLink=React.string("title 2 addCardLink"),
    ~cards=[||],
    (),
  ),
|];

[@react.component]
let make = () =>
  <div className="container"> <ReactTrello data={"lanes": data} /> </div>;

```