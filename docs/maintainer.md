# Maintainence Documentation
Preface for any contributors.

---
## Versioning
Version: Major.Minor.Patch
- Major version describes API boundaries
- Minor version describes ABI boundaries
- Patch version describes non-breaking changes.

Increment Patch for fixes or additional features which don't break ABI (or API).

Increment Minor when an ABI incompatibility will occur and the user will have to rebuild.

Increment Major with any breaking API change.

---
## Git Workflow
- keep main branch at latest production ready state
- each major version gets it's own develop-Major.x branch
- features for each major version will start their own branch off of the appropriate develop branch
- feature branch will pull request into the develop branch
- each minor version will get its own release-Major.Minor.x branch
- the latest release branch will always merge back into the develop branch
- when a full release is established create a Major.Minor.Patch tag then merge into main if the latest
- fixes will merge off of the oldest affected release branch, the merge or cherry pick the fix onto all other applicable release branches with the latest of each major version megering back into trunk.

TODO: Create a diagram which clearly explain all these steps.

---
## Pull requests
Will have to pass code review and automated tooling: tests, formatting, analysis, etc.