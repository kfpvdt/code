const path = require('path');

module.exports = {
  mode: 'development',
  entry: path.resolve(__dirname, 'code/vue2/组件开发/index.js'),
  output: {
    filename: 'bundle.js',
    path: path.resolve(__dirname, 'dist')
  },
  module: {
    rules: [
      {
        test: /\.vue$/,
        loader: 'vue-loader'
      },
      {
        test: /\.js$/,
        exclude: /node_modules/,
        use: {
          loader: 'babel-loader',
          options: {
            presets: ['@babel/preset-env']
          }
        }
      }
    ]
  },
  resolve: {
    alias: {
      '@': path.resolve(__dirname, 'code/vue2/组件开发/'),
      'components': path.resolve(__dirname, 'code/vue2/组件开发/component/'),
      'vue$': 'vue/dist/vue.esm.js'
    },
    extensions: ['.*', '.js', '.vue', '.json']
  }
};
