#!/usr/bin/awk -f
BEGIN {
    print "#include <unistd.h>"
    print "#include <stdio.h>"
    print "int main(void) {"
}
$1 == "sysconf" {
    print "#ifdef " $2
    print "    printf(\"" $2 " defined to be %d\\n\", " $2 ");"
    print "    printf(\"" $2 " = %ld\\n\", sysconf(" $2 "));"
    print "#else"
    print "    printf(\"no symbol for " $2 "\\n\");"
    print "#endif"
}
$1 == "pathconf" {
    print "#ifdef " $2
    print "    printf(\"" $2 " defined to be %d\\n\", " $2 ");"
    print "    printf(\"" $2 " = %ld\\n\", pathconf(\"/\", " $2 "));"
    print "#else"
    print "    printf(\"no symbol for " $2 "\\n\");"
    print "#endif"
}
END {
    print "    return 0;"
    print "}"
}