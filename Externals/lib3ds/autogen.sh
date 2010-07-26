#! /bin/sh

DIE=0

(autoconf --version) < /dev/null > /dev/null 2>&1 || {
  echo
  echo "**Error**: You must have \`autoconf' installed ."
  DIE=1
}

(automake --version) < /dev/null > /dev/null 2>&1 || {
  echo
  echo "**Error**: You must have \`automake' installed."
  DIE=1
  NO_AUTOMAKE=yes
}

(aclocal --version) < /dev/null > /dev/null 2>&1 || {
  echo
  echo "**Error**: Missing \`aclocal'."
  DIE=1
}

if [ $DIE -eq 1 ]; then
  echo "Aborting."
  exit 1
fi

ACLOCAL_SHARE=`which aclocal | sed s/bin/share/`
for d in $SUPPORT_PATHS; do
  if test -d $d/aclocal -a $d/aclocal != $ACLOCAL_SHARE; then
    ACLOCAL_FLAGS="-I $d/aclocal $ACLOCAL_FLAGS"
  fi
done
aclocal $ACLOCAL_FLAGS
libtoolize --force
autoheader
automake --add-missing --copy 
autoconf
