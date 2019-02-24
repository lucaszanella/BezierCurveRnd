# BezierCurveRnd

Example of custom QQuickItem view usage with react-native-desktop

## Launching
```
git clone https://github.com/vkjr/BezierCurveRnd.git
cd BezierCurveRnd/
yarn install
react-native desktop //On "Overwrite index.desktop.js?" question answer "n"
npm start // In a separate shell
node_modules/react-native/ubuntu-server.js // In a separate shell
react-native run-desktop
```

## Implementation details
Implementation of native module resides here - https://github.com/vkjr/BezierCurveRnd/tree/master/modules/react-native-bezier-curve/desktop

In `package.json` specified new native module:
https://github.com/vkjr/BezierCurveRnd/blob/master/package.json#L10

In `index.desktop.js` native component imported:
https://github.com/vkjr/BezierCurveRnd/blob/master/index.desktop.js#L16
And used:
https://github.com/vkjr/BezierCurveRnd/blob/master/index.desktop.js#L24

Since native component written as a QQuickItem it has no react-native properties specific to every View, so its properties should be set manually:
https://github.com/vkjr/BezierCurveRnd/blob/master/modules/react-native-bezier-curve/desktop/beziercurvemanager.cpp#L40

To make QQuickitem component behave like other react-native views it should inherit this class:
https://github.com/status-im/react-native-desktop/blob/master/ReactQt/runtime/src/reactitem.h
and `paint()` function should be reused.

To add flexbox properties to QQuickItem component it should have `flexbox` property. You can look how it set in View.qml and adjust QQuickItem accordingly: 
https://github.com/status-im/react-native-desktop/blob/master/ReactQt/runtime/src/qml/ReactView.qml

