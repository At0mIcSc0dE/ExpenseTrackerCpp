# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

# This is a reminder that you are using a generated .pro file.
# Remove it when you are finished editing this file.
message("You are running qmake on a generated .pro file. This may not work!")


HEADERS += ./header/Calculator.h \
    ./header/Expense.h \
    ./header/Config.h \
    ./header/User.h \
    ./header/Timer.h \
    ./vendor/NetLib/boost/mime.hpp \
    ./vendor/NetLib/boost/network.hpp \
    ./vendor/NetLib/boost/network/constants.hpp \
    ./vendor/NetLib/boost/network/detail/debug.hpp \
    ./vendor/NetLib/boost/network/detail/directive_base.hpp \
    ./vendor/NetLib/boost/network/detail/wrapper_base.hpp \
    ./vendor/NetLib/boost/network/include/http/client.hpp \
    ./vendor/NetLib/boost/network/include/http/server.hpp \
    ./vendor/NetLib/boost/network/include/message.hpp \
    ./vendor/NetLib/boost/network/message.hpp \
    ./vendor/NetLib/boost/network/message/directives.hpp \
    ./vendor/NetLib/boost/network/message/directives/detail/string_directive.hpp \
    ./vendor/NetLib/boost/network/message/directives/detail/string_value.hpp \
    ./vendor/NetLib/boost/network/message/directives/header.hpp \
    ./vendor/NetLib/boost/network/message/directives/remove_header.hpp \
    ./vendor/NetLib/boost/network/message/modifiers/add_header.hpp \
    ./vendor/NetLib/boost/network/message/modifiers/body.hpp \
    ./vendor/NetLib/boost/network/message/modifiers/clear_headers.hpp \
    ./vendor/NetLib/boost/network/message/modifiers/destination.hpp \
    ./vendor/NetLib/boost/network/message/modifiers/remove_header.hpp \
    ./vendor/NetLib/boost/network/message/modifiers/source.hpp \
    ./vendor/NetLib/boost/network/message/traits/body.hpp \
    ./vendor/NetLib/boost/network/message/traits/destination.hpp \
    ./vendor/NetLib/boost/network/message/traits/headers.hpp \
    ./vendor/NetLib/boost/network/message/traits/source.hpp \
    ./vendor/NetLib/boost/network/message/transformers.hpp \
    ./vendor/NetLib/boost/network/message/transformers/selectors.hpp \
    ./vendor/NetLib/boost/network/message/transformers/to_lower.hpp \
    ./vendor/NetLib/boost/network/message/transformers/to_upper.hpp \
    ./vendor/NetLib/boost/network/message/wrappers.hpp \
    ./vendor/NetLib/boost/network/message/wrappers/body.hpp \
    ./vendor/NetLib/boost/network/message/wrappers/destination.hpp \
    ./vendor/NetLib/boost/network/message/wrappers/headers.hpp \
    ./vendor/NetLib/boost/network/message/wrappers/source.hpp \
    ./vendor/NetLib/boost/network/message_fwd.hpp \
    ./vendor/NetLib/boost/network/protocol.hpp \
    ./vendor/NetLib/boost/network/protocol/http.hpp \
    ./vendor/NetLib/boost/network/protocol/http/algorithms/linearize.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/async_impl.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/connection/async_base.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/connection/async_normal.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/connection/async_protocol_handler.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/connection/connection_delegate.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/connection/connection_delegate_factory.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/connection/normal_delegate.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/connection/ssl_delegate.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/connection/sync_base.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/connection/sync_normal.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/connection/sync_ssl.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/facade.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/macros.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/options.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/pimpl.hpp \
    ./vendor/NetLib/boost/network/protocol/http/client/sync_impl.hpp \
    ./vendor/NetLib/boost/network/protocol/http/errors.hpp \
    ./vendor/NetLib/boost/network/protocol/http/impl/request.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/async_message.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/directives/major_version.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/directives/method.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/directives/minor_version.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/directives/status.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/directives/status_message.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/directives/uri.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/directives/version.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/header.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/header/name.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/header/value.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/message_base.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/modifiers/body.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/modifiers/clear_headers.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/modifiers/destination.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/modifiers/headers.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/modifiers/major_version.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/modifiers/method.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/modifiers/minor_version.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/modifiers/source.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/modifiers/status.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/modifiers/status_message.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/modifiers/uri.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/modifiers/version.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/traits/status.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/traits/status_message.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/traits/version.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/anchor.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/body.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/destination.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/headers.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/helper.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/host.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/major_version.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/method.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/minor_version.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/path.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/port.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/protocol.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/query.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/ready.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/source.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/status.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/status_message.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/uri.hpp \
    ./vendor/NetLib/boost/network/protocol/http/message/wrappers/version.hpp \
    ./vendor/NetLib/boost/network/protocol/http/parser.hpp \
    ./vendor/NetLib/boost/network/protocol/http/parser/incremental.hpp \
    ./vendor/NetLib/boost/network/protocol/http/policies/async_connection.hpp \
    ./vendor/NetLib/boost/network/protocol/http/policies/async_resolver.hpp \
    ./vendor/NetLib/boost/network/protocol/http/policies/pooled_connection.hpp \
    ./vendor/NetLib/boost/network/protocol/http/policies/simple_connection.hpp \
    ./vendor/NetLib/boost/network/protocol/http/policies/sync_resolver.hpp \
    ./vendor/NetLib/boost/network/protocol/http/request.hpp \
    ./vendor/NetLib/boost/network/protocol/http/request_parser.hpp \
    ./vendor/NetLib/boost/network/protocol/http/response.hpp \
    ./vendor/NetLib/boost/network/protocol/http/server.hpp \
    ./vendor/NetLib/boost/network/protocol/http/server/async_connection.hpp \
    ./vendor/NetLib/boost/network/protocol/http/server/async_server.hpp \
    ./vendor/NetLib/boost/network/protocol/http/server/options.hpp \
    ./vendor/NetLib/boost/network/protocol/http/server/request.hpp \
    ./vendor/NetLib/boost/network/protocol/http/server/request_parser.hpp \
    ./vendor/NetLib/boost/network/protocol/http/server/socket_options_base.hpp \
    ./vendor/NetLib/boost/network/protocol/http/server/storage_base.hpp \
    ./vendor/NetLib/boost/network/protocol/http/support/client_or_server.hpp \
    ./vendor/NetLib/boost/network/protocol/http/support/is_client.hpp \
    ./vendor/NetLib/boost/network/protocol/http/support/is_http.hpp \
    ./vendor/NetLib/boost/network/protocol/http/support/is_keepalive.hpp \
    ./vendor/NetLib/boost/network/protocol/http/support/is_server.hpp \
    ./vendor/NetLib/boost/network/protocol/http/support/is_simple.hpp \
    ./vendor/NetLib/boost/network/protocol/http/tags.hpp \
    ./vendor/NetLib/boost/network/protocol/http/traits.hpp \
    ./vendor/NetLib/boost/network/protocol/http/traits/connection_keepalive.hpp \
    ./vendor/NetLib/boost/network/protocol/http/traits/connection_policy.hpp \
    ./vendor/NetLib/boost/network/protocol/http/traits/delegate_factory.hpp \
    ./vendor/NetLib/boost/network/protocol/http/traits/message_traits.hpp \
    ./vendor/NetLib/boost/network/protocol/http/traits/parser_traits.hpp \
    ./vendor/NetLib/boost/network/protocol/http/traits/resolver.hpp \
    ./vendor/NetLib/boost/network/protocol/http/traits/resolver_policy.hpp \
    ./vendor/NetLib/boost/network/protocol/stream_handler.hpp \
    ./vendor/NetLib/boost/network/support/is_async.hpp \
    ./vendor/NetLib/boost/network/support/is_default_string.hpp \
    ./vendor/NetLib/boost/network/support/is_default_wstring.hpp \
    ./vendor/NetLib/boost/network/support/is_http.hpp \
    ./vendor/NetLib/boost/network/support/is_keepalive.hpp \
    ./vendor/NetLib/boost/network/support/is_pod.hpp \
    ./vendor/NetLib/boost/network/support/is_simple.hpp \
    ./vendor/NetLib/boost/network/support/is_sync.hpp \
    ./vendor/NetLib/boost/network/support/is_tcp.hpp \
    ./vendor/NetLib/boost/network/support/is_udp.hpp \
    ./vendor/NetLib/boost/network/support/pod_or_normal.hpp \
    ./vendor/NetLib/boost/network/tags.hpp \
    ./vendor/NetLib/boost/network/traits/char.hpp \
    ./vendor/NetLib/boost/network/traits/headers_container.hpp \
    ./vendor/NetLib/boost/network/traits/istream.hpp \
    ./vendor/NetLib/boost/network/traits/istringstream.hpp \
    ./vendor/NetLib/boost/network/traits/ostream_iterator.hpp \
    ./vendor/NetLib/boost/network/traits/ostringstream.hpp \
    ./vendor/NetLib/boost/network/traits/string.hpp \
    ./vendor/NetLib/boost/network/traits/vector.hpp \
    ./vendor/NetLib/boost/network/uri.hpp \
    ./vendor/NetLib/boost/network/uri/accessors.hpp \
    ./vendor/NetLib/boost/network/uri/builder.hpp \
    ./vendor/NetLib/boost/network/uri/config.hpp \
    ./vendor/NetLib/boost/network/uri/decode.hpp \
    ./vendor/NetLib/boost/network/uri/detail/uri_parts.hpp \
    ./vendor/NetLib/boost/network/uri/directives.hpp \
    ./vendor/NetLib/boost/network/uri/directives/authority.hpp \
    ./vendor/NetLib/boost/network/uri/directives/fragment.hpp \
    ./vendor/NetLib/boost/network/uri/directives/host.hpp \
    ./vendor/NetLib/boost/network/uri/directives/path.hpp \
    ./vendor/NetLib/boost/network/uri/directives/port.hpp \
    ./vendor/NetLib/boost/network/uri/directives/query.hpp \
    ./vendor/NetLib/boost/network/uri/directives/scheme.hpp \
    ./vendor/NetLib/boost/network/uri/directives/user_info.hpp \
    ./vendor/NetLib/boost/network/uri/encode.hpp \
    ./vendor/NetLib/boost/network/uri/schemes.hpp \
    ./vendor/NetLib/boost/network/uri/uri.hpp \
    ./vendor/NetLib/boost/network/uri/uri_io.hpp \
    ./vendor/NetLib/boost/network/utils/base64/encode-io.hpp \
    ./vendor/NetLib/boost/network/utils/base64/encode.hpp \
    ./vendor/NetLib/boost/network/utils/thread_group.hpp \
    ./vendor/NetLib/boost/network/utils/thread_pool.hpp \
    ./vendor/NetLib/boost/network/version.hpp \
    ./header/Declarations.h \
    ./header/JSON.h \
    ./header/WindowDesign.h \
    ./header/MainWindow.h \
    ./header/button.h \
    ./header/combobox.h \
    ./header/listbox.h \
    ./header/plaintext.h \
    ./header/spinbox.h \
    ./header/LoginWindow.h \
    ./header/textbox.h \
    ./header/checkbox.h \
    ./header/Network.h
SOURCES += ./src/Calculator.cpp \
    ./src/Expense.cpp \
    ./src/Config.cpp \
    ./src/JSON.cpp \
    ./src/LoginWindow.cpp \
    ./src/checkbox.cpp \
    ./src/button.cpp \
    ./src/combobox.cpp \
    ./src/listbox.cpp \
    ./src/main.cpp \
    ./src/MainWindow.cpp \
    ./src/plaintext.cpp \
    ./src/spinbox.cpp \
    ./src/textbox.cpp \
    ./src/User.cpp \
    ./src/Timer.cpp \
    ./src/Network.cpp
FORMS += ./form/loginwindow.ui \
    ./form/MainWindow.ui
RESOURCES += MainWindow.qrc