# Renovation Theme

Theme for Webspark 2: Implements Web Standards 2.0

## Installation for local development

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


## Update Renovation with changes from Unity

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

3. Compile the changes (for local development)

To test, you need to compile the changes `npm run dev` or `yarn dev`
To test in the test environment push also the compiled css assets/css/renovation.style.css. (Note: for release, we don't push the compile css until all pull requests are merged. This helps us avoid conflicts.)

### JS Update

When new components add Javascript to the `bootstrap4_theme` the JS needs to be incorporated into the Renovation theme, and this may require some adjustements to use Drupal behaviors.

1. Clone the repository or particular file from https://github.com/ASU/asu-unity-stack/

2. Search for the component js file in https://github.com/ASU/asu-unity-stack/tree/dev/packages/bootstrap4-theme/stories

Do not consider the *.templates.js

3. Create or search for the file in our repository [theme_folder]/src/components/[component]

4. Copy the code inside a Drupal behavior

4.1. Tip: Search for examples in other components to see how this is done.

### Push to repository

If doing development in a team sandbox site, the following steps explain commiting your sandbox changes back to the main repository to create a pull request.

1. Clone (if you did not do it yet) the theme repository https://github.com/ASUWebPlatforms/webspark-theme-renovation

2. Create another branch

3. Add the modified files

4. Push the changes. !Important  Do not push the compiles css (This is only done at the end of development, while preparing a releease).

5. Create a pull request.

### Release

1. Clone (if you did not do it yet) the theme repository https://github.com/ASUWebPlatforms/webspark-theme-renovation

2. Create another branch

3. Follow the steps under "Update Renovation with changes from Unity" but use the command below to compile the assets.

4. Compile the assets using "npm run production"

5. Push the changes. !Important  Do not push the compiles css

6. Create a pull request for this theme's repo.

Once all PRs for the release are merged and the release is ready, the final step is to compile and push the CSS to this theme and create the tag, and update the upstream with that tag.

## Layout builder related changes

Some of the classes from the core layout builder had to be changed. Because the core ones override everything we write here, we had to disable them from .info file and recreate them in the /css folder.


## Known limitations

 - The versions for used libraries are pinned. you will find them in package.json. Because of this there are differences between bootstrap versions. We created a file to handle this differences: /src/sass/bootstrap-asu-upgrade.scss.


## Unity bootstrap4-theme package / Renovation directories and mappings

* https://github.com/ASUWebPlatforms/webspark-theme-renovation/tree/main/src/sass corresponds with https://github.com/ASU/asu-unity-stack/tree/dev/packages/bootstrap4-theme/src/scss with additional folders added for WS2 overrides and tweaks.
* Don’t alter these 1:1 copies from UDS:
  * `src/sass/extends`
  * `src/sass/design-tokens`
  * `src/sass/variables`
* Relay updates from UDS into these, but avoid breaking overrides and additional includes:
  * `src/sass/bootstrap-asu-extends.scss`
  * `src/sass/bootstrap-asu.scss`
* Renovation additions and tweaks
  * `src/sass/bootstrap-asu-upgrade.scss` - tweaks for Bootstrap version differences between UDS bootstrap4-theme and Radix
  * `src/sass/renovation.style.scss` - Renovation Bootstrap imports
* Renovation component SCSS mappings, custom SCSS and Twig templates for Renovation live in - Twig versions of Unity Storybook templates:
`src/components`
* Drupal-based Twig templates:
`templates/`
* Preprocess functions. Inherited from how Radix does it:
`includes/`
* When doing release, SCSS and JS assets are compiled manually and go into:
`assets/`
