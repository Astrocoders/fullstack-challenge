const passport = require('passport')
const { Strategy: TwitterStrategy } = require('passport-twitter')

const { TWITTER_CONFIG } = require('../config')

module.exports = () => {
    passport.serializeUser((user, cb) => cb(null, user))
    passport.deserializeUser((obj, cb) => cb(null, obj))

    const callback = (accessToken, refreshToken, profile, cb) => cb(null, profile)

    passport.use(new TwitterStrategy(TWITTER_CONFIG, callback))
}