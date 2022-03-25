# Renovation Theme
Theme for Webspark 2: Implements Web Standards 2.0

Contents
- [Renovation Theme](#renovation-theme)
  - [General Information](#general-information)
  - [Developer Information](#developer-information)
    - [Set up local development](#set-up-local-development)
    - [Reconciling Unity with Renovation](#reconciling-unity-with-renovation)
    - [How to compile Sass files for release](#how-to-compile-sass-files-for-release)
  - [Caveats](#caveats)

## General Information
This theme is bundled with ASU's Drupal 9+ custom profile, Webspark 2. When spinning up a new site, if you select the ASU Webspark installation profile, this theme will be automatically installed and selected as the default theme.

The Renovation theme is a subtheme of the Radix theme. Radix will need to remain enabled in order for Renovation to work properly. You can further customize your site by creating a subtheme of Renovation, but this is only to be done with extreme caution. Subthemed sites will not be supported officially by the University Technology Office, due to the difficulty of troubleshooting issues that may arise. So, please make sure you have adequate developer resources at your disposal in order to create and maintain your subtheme.

The Renovation theme utilizes [Sass](https://sass-lang.com/) for the creation and maintenance of site styles. This enables us to use variables, mix-ins, and other tools to make the theme development experience more efficient and enjoyable. Renovation's Sass  code relies on [Webpack](https://webpack.js.org) to compile it into standard CSS and JavaScript.

The Renovation theme is an extension and outgrowth of the platform-agnostic Unity Design System's (UDS) customized [bootstrap4-theme](https://github.com/ASU/asu-unity-stack/tree/dev/packages/bootstrap4-theme). The Unity bootstrap4-theme has been modified slightly in Renovation to accommodate the [Twig](https://twig.symfony.com/) templating engine, and contains other Drupal-specific modifications while staying true to the standards established in UDS.

#

## Developer Information
Due to the fact that this theme is somewhat different from the source content in UDS, included below are instructions for Renovation's theme maintainers on how to reconcile those differences, especially when preparing for Webspark 2 releases.

### Set up local development
1. Clone repository from Github to your local development environment (https://github.com/ASUWebPlatforms/webspark-theme-renovation). If you are unable to access the repository, contact the Web Platforms Development team for assistance.
2. Create a new branch locally (ideally named in reference to a Jira ticket, such as WS2-NNN) with `git checkout -b branchname`.
3. Push your new branch up to the Github repository and set up remote tracking: `git push -u origin branchname`

### Reconciling Unity with Renovation
1. Determine which files have changed since the last Webspark2 release.
    - Use the [check-element-changes](https://github.com/ASU/asu-unity-stack#check-element-changes) tool in UDS to determine which files need attention. This tool will alert you to which components have had changes in their code since a date you specify. It also instructs you to run a git command to see ALL of the files that have changed since the selected date.
2. For each **COMPONENT** which has changed, clone the corresponding repository from UDS to your local environment. Since Unity is a mono-repo, you really only need to clone https://github.com/ASU/asu-unity-stack and make sure it is up-to-date. You can find the components in their respective stories (organisms, molecules, etc) within the bootstrap4-theme.
   1. The component will map to the **src/components** directory within the Renovation theme. For example, ```asu-unity-stack/packages/bootstrap4-theme/stories/molecules/tabbed-panels``` correlates with ```webspark-theme-renovation/src/components/tabbed-panels```. In these two directories, you will often find more than one JavaScript files.
   2. You can roughly connect the `*.templates.js` file with the `*.twig` file for the component in Renovation. Make note of any changes in the `*.templates.js` file and adjust the `*.twig` file accordingly.
   3. The `*.js` file in UDS will sometimes match the `*.js` file in Renovation, but sometimes changes have been made to accommodate the Drupal way of doing things. The most common of these differences will often be related to Drupal behaviors. See the [JavaScript API documentation](https://www.drupal.org/docs/drupal-apis/javascript-api/javascript-api-overview) for more information. Because of the potential for differences, please **DO NOT** simply copy/paste this file from UDS to Renovation. Instead, open the file in both repositories and compare what you see in UDS with what you find in Renovation. If there are changes, manually add those changes to the Renovation file. The code from UDS may need to be wrapped in a Drupal behavior in order to make it work.
3. To update and compile the **Sass/CSS**, you will need to copy some of the Sass files from UDS to Renovation, and some of them you will need to edit in the manner described above. The source files in UDS are located at `asu-unity-stack/packages/bootstrap4-theme/src/scss/`. This directory contains several subdirectories and files. The destination directory in Renovation is: `webspark-theme-renovation/src/sass/`. As you will notice, the contents of these directories is similar, but not exactly the same. The following information will help explain the differences.
   1. The `design-tokens` folder contains a `_variables.scss` file which can be copied verbatim from UDS to Renovation. A second file, `_extra-vars.scss` exists in Renovation for Drupal-specific styles.
   2. The `extends` folder contains customized bootstrap files that can be copied directly from UDS without any alteration into the Renovation theme.
   3. The `variables` folder contains customized bootstrap files that can be copied directly, except there is a `_tabs.scss` file in Renovation that does not exist in UDS.
   4. The other directories in Renovation contain additional styles that are unique to Renovation and Drupal.
   5. There are several files that aggregate and import many of the scss files. Specific instructions about them are as follows:
      - `bootstrap-asu-extends.scss`: You will notice that this file is significantly different in Renovation from what you see in UDS. This is because the paths to the styles are necessarily different, due to the fact that the components are being added differently in Drupal than in Unity. Please note the `../components/` paths on some imports, whereas some of them directly pull from `extends/`. **DO NOT** copy/paste this file directly, but rather go through it line-by-line to ensure all styles are imported.
      - `bootstrap-asu.scss`: Similarly, this file imports many styles from bootstrap into the theme. Please note that the `$image-assets-path` is different in Renovation than UDS (the image file in Renovation is located up one level in the codebase).
   6. `bootstrap-asu-upgrade.scss`: This file reconciles the fact that UDS and Renovation are currently on different versions of Bootstrap. It brings the two into alignment in Renovation.
   7. The other files and folders contain Renovation-specific styles.
   8. **PLEASE NOTE:** When updating components or Sass files in preparation for a Webspark2 release, it is important not to push the compiled Sass and JS assets until all pull requests have been merged. This helps to avoid regressions and conflicts.

### How to compile Sass files for release
1. Go to the root of Renovation theme and run the following commands: `npm install` or `yarn install`.
2. Run the following command to compile Sass and watch for changes: `npm run watch` or `yarn watch`.
3. Make changes as described in "Reconciling Unity with Renovation."
4. When you have finished making your changes, compile the assets for production by running `npm run production`. **Important!** Do not add the compiled assets (found in `assets/css` and `assets/js`) to your git commit at this point.
5. Add all other changed files with `git add path/file`.
6. Commit changes in git and push to the remote repository.
7. Create a pull request against the `main` branch.
8. Verify that **ALL** pending pull requests for the release have been merged.
9. Pull all the latest changes into your branch from the main branch with `git pull origin main`.
10. Fix any conficts, if necessary, and commit your changes.
11. When you feel that the release is ready, the final step is to compile and push the CSS. Do this by running `npm run production` again. This time, make sure that you add the changed files in the `assets` directory with `git add` and then commit the changes.
12. Push the commit to the remote repository.
13. When your pull request has been approved, merge it into the main branch.
14.  Create a new tag for the release (using semantic versioning principles), and update the composer.json file in `webspark-release-testing/upstream-configuration/` with that tag for `"asuwebplatforms/webspark-theme-renovation"`.
15.  Increment the version number at the bottom of the composer.json file.
16.  That's it! Submit the release for testing and do a happy dance (until you get bug reports back).

## Caveats
- Some of the classes from the core layout builder had to be changed. Because the core ones override everything we write here, we had to disable them from .info file and recreate them in the /css folder.
- The versions for libraries being used in this theme are **pinned**. You will be able to find the version numbers in package.json.
- Working on the theme can be made easier by utilizing the `watch` feature provided by webpack (as mentioned in Step 2 of "How to compile Sass files for release"). However, getting set up to do this can be tricky. To make it work, you will need to update the `proxy` value in the `webpack.mix.json` file to match your local development environment. The default example is for use with DDEV, but it can be changed to whatever you use for local development. For more information on developing with the Radix theme using webpack, check out this excellent [tutorial](https://www.youtube.com/watch?v=ak1IOcYnN9s).
