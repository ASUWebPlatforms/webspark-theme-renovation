# Renovation Theme

Theme for Webspark 2: Implements Web Standards 2.0

## Installation

Ensure that the Radix theme and the components moule are installed. Later we can decouple this.

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


## UDS to Renovation

Here we explain how to update the code that comes from the UDS (Unity).

### Unity site

In this storybook you see how to elements look:
https://unity.web.asu.edu/@asu-design-system/bootstrap4-theme/

### Unity repository

Here is the unity repository:
https://github.com/ASU/asu-unity-stack/

### SASS Update

In order to update the CSS from the Unity you will need to follow these steps:

1. Clone the repository or particular file from https://github.com/ASU/asu-unity-stack/
2. Copy the scss files or contents from https://github.com/ASU/asu-unity-stack/tree/dev/packages/bootstrap4-theme/src/scss
and override the existing files.

!IMPORTANT
Do not change those files in other way. The changes will be lost.

3. Compile the changes

To test, you need to compile the changes `npm run dev` or `yarn dev`
To test in the test environment push also the compiled css assets/css/renovation.style.css

### JS Update

1. Clone the repository or particular file from https://github.com/ASU/asu-unity-stack/

2. Search for the component js file in https://github.com/ASU/asu-unity-stack/tree/dev/packages/bootstrap4-theme/stories

Do not consider the *.templates.js

3. Create or search for the file in our repository [theme_folder]/src/components/[component]

4. Copy the code inside a Drupal behavior

4.1. Helper: Search for other existing examples in other components.

### Push to repository

1. Clone (if you did not do it yet) the theme repository https://github.com/ASUWebPlatforms/webspark-theme-renovation

2. Create another branch

3. Add the modified files

4. Push the changes. !Important  Do not push the compiles css

5. Create a pull request.


## Layout builder related changes

Some of the classes from the core layout builder had to be changed. Because the core ones override everything we write here, we had to disable them from .info file and recreate them in the /css folder.


## Known limitations

 - The versions for used libraries are pinned. you will find them in package.json. Because of this there are differences between bootstrap versions. We created a file to handle this differences: /src/sass/bootstrap-asu-upgrade.scss.
