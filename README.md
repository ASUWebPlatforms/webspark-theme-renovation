#Renovation Theme

Theme for Webspark 2: Implements Web Standards 2.0

## Installation

Ensure that the Radix theme is installed. Later we can decouple this.

For historical reasons when cloning this repo use:

`git clone git@github.com:ASUWebPlatforms/webspark-theme-renovation.git renovation`

This avoids any confusion as to the name of the theme.

Renovation theme uses [Webpack](https://webpack.js.org) to compile and bundle SASS and JS.

#### Step 1
Make sure you have Node and npm installed.
You can read a guide on how to install node here: https://docs.npmjs.com/getting-started/installing-node

If you prefer to use [Yarn](https://yarnpkg.com) instead of npm, install Yarn by following the guide [here](https://yarnpkg.com/docs/install).

#### Step 2
Go to the root of Renovation theme and run the following commands: `npm install` or `yarn install`.

#### Step 3
Update `proxy` in **webpack.mix.json**.

#### Step 4
Run the following command to compile Sass and watch for changes: `npm run watch` or `yarn watch`.
