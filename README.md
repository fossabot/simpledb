## Prerequisites
```bash
apt install libsqlite3-dev

(or brew)
```

You may need to install `cmake-js` as well
```
npm install -g cmake-js
```


## Install
```bash
npm i simpledb
```

## Example
See `example/`

### CREATE
```js
const {Connection} = require('simpledb');

let connection = new Connection(db);
let stmt = connection.createStatement();
stmt.execute(`CREATE TABLE ${table}(idx INTEGER PRIMARY KEY AUTOINCREMENT, passwd TEXT, date DATETIME);`)
.then(res => {
  console.log(res);
})
```

### INSERT
```js
let connection = new Connection(db);
let stmt = connection.createStatement();
let query =  `INSERT INTO ${table} (passwd, date) VALUES(${Math.random()},datetime(\'now\',\'localtime\'));`;
stmt.execute(query)
.then(res => {
  console.log(res);
})
```

### SELECT
```js
let connection = new Connection(db);
let stmt = connection.createStatement();
stmt.executeQuery('SELECT idx, passwd, date FROM admin')
.then(res => {
  while(res.next()) {
    console.log(`${res.getInt(0)}, ${res.getString(1)}, ${res.getString(2)}`);
  }
})
```

### UPDATE
```js
let stmt = connection.createStatement();
let password = 'new password';
let query = `UPDATE ${table} set passwd=\'${password}\', date=datetime(\'now\',\'localtime\') WHERE idx=1;`;
stmt.execute(query)
.then(res =>{
  console.log(res);
})
```

### DELETE
```js
let stmt = connection.createStatement();
let id = 1;
stmt.execute(`DELETE FROM admin WHERE idx=${id};`)
.then(res => {
  console.log(res);
})
```


## (Optional) Native only build
```bash
cd native;
mkdir build; cd build
cmake .. && make
```
