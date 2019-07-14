require('dotenv').config()
const express = require('express')
//const path = require('path')
//const fs = require('fs')
const http = require('http')
const passport = require('passport')
const session = require('express-session')
const cors = require('cors')
const socketio = require('socket.io')

const authRouter = require('./lib/auth.router')
const passportInit = require('./lib/passport.init')

const app = express()

const server = http.createServer(app)

app.use(express.json())
app.use(passport.initialize())

passportInit()

app.use(cors())

app.use(session({
    secret: 'batman',
    resave: true,
    saveUninitialized: true
}))

const io = socketio(server)

app.set('io', io)

app.use('/', authRouter)

server.listen(process.env.PORT || 8080, () => {
    console.log('ლ(ಠ益ಠ)ლ')
})