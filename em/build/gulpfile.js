'use strict';

var gulp = require('gulp'),
  livereload = require('gulp-livereload'),
  gulpIf = require('gulp-if'),
  eslint = require('gulp-eslint'),
  sass = require('gulp-sass'),
  autoprefixer = require('gulp-autoprefixer'),
  sourcemaps = require('gulp-sourcemaps'),
  rename = require('gulp-rename'),
  uglify = require('gulp-uglify-es').default,
  imagemin = require('gulp-imagemin'),
  pngquant = require('imagemin-pngquant');


var vendorDir = '../themes/charm/vendor';
var assetsDir = '../assets';
var srcDir = '../_src';

var config = {
  'scss': {
    'srcDir': srcDir + '/scss/**/*.*',
    'srcFiles': srcDir + '/scss/**/*.scss',
    'includePath': vendorDir,
    'sourcemaps': 'sourcemaps',
    'dest': assetsDir + '/css'
  },
  'js': {
    'srcDir': srcDir + '/js/',
    'srcFiles': srcDir + '/js/**/*.js',
    'sourcemaps': './sourcemaps',
    'dest':  assetsDir + "/js",
  },
  'images': {
    'src': srcDir + 'images/*',
    'dest': assetsDir + 'images'
  }
};


gulp.task('imagemin', function () {
  return gulp.src(config.images.src)
    .pipe(imagemin({
      progressive: true,
      svgoPlugins: [{removeViewBox: false}],
      use: [pngquant()]
    }))
    .pipe(gulp.dest(config.images.dest));
});


/**
 * Sass Output Styles
 * :nested
 * :compact
 * :expanded
 * :compressed
 */
gulp.task('sass', function () {
  gulp.src(config.scss.srcFiles)
    .pipe(sourcemaps.init())
    .pipe(sass({
      outputStyle: 'expanded',
      includePaths: config.scss.includePath,
    }).on('error', sass.logError))
    .pipe(autoprefixer('>1%','last 2 version','ie >= 11'))
    .pipe(sourcemaps.write(config.scss.sourcemaps))
    .pipe(gulp.dest(config.scss.dest));
});


function isError(file) {
  // Has ESLint fixed the file contents?
  console.log( file.eslint.error );
}

function isFixed(file) {
  // Has ESLint fixed the file contents?
  return file.eslint !== null && file.eslint.fixed;
}


gulp.task("compress", function () {
  return gulp.src(config.js.srcFiles)
    .pipe(rename({suffix: '.min'}))
    .pipe(uglify())
    .pipe(gulp.dest(config.js.dest));
});

gulp.task('watch', function() {
  livereload.listen();

  gulp.watch(config.scss.srcDir, ['sass']);
  gulp.watch(config.js.srcFiles, ['compress']);
  gulp.watch([config.scss.dest + '/**/*.css', '../templates/**/*.html.twig'], function (files) {
   // livereload.changed(files);
  });
});
