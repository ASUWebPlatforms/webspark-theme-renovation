# Renovation Theme
Theme for Webspark 2: Implements Web Standards 2.0

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

### Reconcile latest changes in UDS with Renovation
1. Determine which files have changed since the last Webspark2 release.
    - Use the [check-element-changes](https://github.com/ASU/asu-unity-stack#check-element-changes) tool in UDS to determine which files need attention. This tool will alert you to which components have had changes in their code since a date you specify. It also instructs you to run a git command to see ALL of the files have changed since that date.
2. For each **COMPONENT** which has changed, clone the corresponding repository from UDS to your local environment. Since Unity is a mono-repo, you really only need to clone https://github.com/ASU/asu-unity-stack and make sure it is up-to-date. You can find the components in their respective stories (organisms, molecules, etc) within the bootstrap4-theme.
   1. The component will map to the **src/components** directory within the Renovation theme. For example, ```asu-unity-stack/packages/bootstrap4-theme/stories/molecules/tabbed-panels``` correlates with ```webspark-theme-renovation/src/components/tabbed-panels```. In these two directories, you will often find more than one JavaScript files.
   2. You can roughly connect the *.templates.js file with the *.twig file for the component in Renovation. Make note of any changes in the *.templates.js file and adjust the *.twig file accordingly.
   3. The *.js file in UDS will sometimes match the *.js file in Renovation, but sometimes changes have been made to accommodate the Drupal way of doing things. The most common of these differences will often be related to Drupal behaviors See the [JavaScript API documentation](https://www.drupal.org/docs/drupal-apis/javascript-api/javascript-api-overview) for more information. Because of the potential for differences, please **DO NOT** simply copy/paste this file from UDS to Renovation. Instead, open the file in both repositories and compare what you see in UDS with what you find in Renovation. If there are changes, manually add those changes to the Renovation file. The code from UDS may need to be wrapped in a Drupal behavior in order to make it work.
3. To update and compile the Sass/CSS, you will need to copy some of the Sass files from UDS to Renovation, and some of them you will need to edit in the manner described above. The source files in UDS are located at `asu-unity-stack/packages/bootstrap4-theme/src/scss/`. This directory contains several subdirectories and files. The destination directory in Renovation is: `webspark-theme-renovation/src/sass/`. As you will notice, the contents of these directories is similar, but not exactly the same. The following information will help describe the differences.
   1. The `design-tokens` folder contains a `_variables.scss` file which can be copied verbatim from UDS to Renovation. A second file, `_extra-vars.scss` exists in Renovation for Drupal-specific styles.
   2. The `extends` folder contains
   3.
`src/sass/bootstrap-asu-extends.scss`
`src/sass/bootstrap-asu.scss`

