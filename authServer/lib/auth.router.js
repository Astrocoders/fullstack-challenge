const express = require('express')
const router = express.Router()
const passport = require('passport')
const authController = require('./auth.controller')

const twitterAuth = passport.authenticate('twitter')

router.get('/twitter/callback', twitterAuth, authController.twitter)

router.use((req, res, next) => {
    req.session.socketId = req.query.socketId
    next()
})

router.get('/twitter', twitterAuth)

module.exports = router
