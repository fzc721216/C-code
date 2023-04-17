#include "byte_stream.hh"

// Dummy implementation of a flow-controlled in-memory byte stream.

// For Lab 0, please replace with a real implementation that passes the
// automated checks run by `make check_lab0`.

// You will need to add private members to the class declaration in `byte_stream.hh`

template <typename... Targs>
void DUMMY_CODE(Targs &&... /* unused */) {}

using namespace std;

ByteStream::ByteStream(const size_t capacity): _capacity(capacity) {}

size_t ByteStream::write(const string &data) {
    size_t len = data.length();
    if (len + _bytestream.size() > _capacity) {
        len = _capacity - _bytestream.size();
    }
    _bytes_written_number += len;
    for (size_t count = 0; count < len; count++) {
        _bytestream.push_back(data[count]);
    }
    return len;
}

//! \param[in] len bytes will be copied from the output side of the buffer
string ByteStream::peek_output(const size_t len) const {
   size_t process_len = len;
   if (process_len > _bytestream.size()) {
        process_len = _bytestream.size();
   }
   return string().assign(_bytestream.begin(), _bytestream.begin() + process_len);
}

//! \param[in] len bytes will be removed from the output side of the buffer
void ByteStream::pop_output(const size_t len) {
   size_t process_len = len;
   if (process_len > _bytestream.size()) {
        process_len = _bytestream.size();
   }
   _bytes_read_number += process_len;
   while (process_len--) {
        _bytestream.pop_front();
   }
}//! \returns a string
std::string ByteStream::read(const size_t len) {
    string output = peek_output(len);
    pop_output(len);
    return output;
}

void ByteStream::end_input() { _is_end = true;}

bool ByteStream::input_ended() const { return _is_end; }

size_t ByteStream::buffer_size() const { return _bytestream.size(); }

bool ByteStream::buffer_empty() const { return _bytestream.empty(); }

bool ByteStream::eof() const { return buffer_empty() && _is_end; }

size_t ByteStream::bytes_written() const { return _bytes_written_number; }

size_t ByteStream::bytes_read() const { return _bytes_read_number; }

size_t ByteStream::remaining_capacity() const {
    return _capacity - _bytestream.size();
}
