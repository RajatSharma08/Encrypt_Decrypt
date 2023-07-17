// index.js (Node.js server-side code)
const express = require('express');
const app = express();
const { spawnSync } = require('child_process');

app.get('/encrypt', (req, res) => {
    const message = req.query.message;
    const shift = req.query.shift;
    const result = spawnSync('./encryption', [message, shift]);
    res.send(result.stdout.toString());
});

app.get('/decrypt', (req, res) => {
    const encryptedMessage = req.query.encryptedMessage;
    const shift = req.query.shift;
    const result = spawnSync('./decryption', [encryptedMessage, shift]);
    res.send(result.stdout.toString());
});

app.listen(3000, () => {
    console.log('Server is running on port 3000');
});
