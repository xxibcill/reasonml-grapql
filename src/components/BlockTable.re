[@react.component]
let make = (~data) => {
    <table>
        <thead>
            <tr>
                <th>{"Height" |> React.string}</th>
                <th>{"Hash" |> React.string}</th>
            </tr>
        </thead>
        <tbody>
            {
                data |> Js.Array.map(e => <BlockRow hash=e##hash height=e##height/>) |> React.array
            }
        </tbody>
    </table>
}
