# Generated from qnetworkcookiejar.pro.

#####################################################################
## tst_qnetworkcookiejar Test:
#####################################################################

# Collect test data
list(APPEND test_data "parser.json")

add_qt_test(tst_qnetworkcookiejar
    SOURCES
        tst_qnetworkcookiejar.cpp
    PUBLIC_LIBRARIES
        Qt::CorePrivate
        Qt::Network
        Qt::NetworkPrivate
    TESTDATA ${test_data}
)
