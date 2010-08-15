#!/bin/sh

set -e

URL='https://smoothwall.svn.sourceforge.net/svnroot/smoothwall/trunk/distrib/build/sources/smoothd/smoothd-0.0'

REV=$(svn info $URL | sed -ne 's/Last Changed Rev: \(.*\)$/\1/p')

TMPDIR=swe3-smoothd_0.0~svn$REV

svn export $URL $TMPDIR
tar czf swe3-smoothd_0.0~svn$REV.orig.tar.gz $TMPDIR
rm -rf $TMPDIR
