#pragma once

#ifndef UNIQUE_POINTER_H
#define UNIQUE_POINTER_H

#include <memory>
#include <atomic>
#include <type_traits>


namespace speck {

    template <typename T>
    struct default_deleter {
        void operator()(T* ptr) noexcept {
            printf("In default deleter\n");
            delete ptr;
        }
    };


    template <typename T, typename deleter = speck::default_deleter<T>> class unique_pointer {
        public:

        /**
         * @brief Construct a new unique pointer object
         * 
         * @param object 
         */
        explicit unique_pointer(T* object = nullptr, deleter d = deleter()) noexcept : _object(object), _deleter(d) { 
            //_deleter = deleter;
        }

        /**
         * @brief Construct a new unique pointer object using copy semantics
         * 
         * @param copy_pointer 
         */
        explicit unique_pointer(speck::unique_pointer<T>&& copy_pointer) noexcept : _object(copy_pointer._object) {
            // Transferring owenship of an rvalue???
            //this = std::move(_copy_pointer);
            copy_pointer._object = nullptr;
        }

        T& operator * () {
            //if (this->_object == nullptr) return nullptr;
            
            return *_object;  
        }

        T* operator -> () { 
            if (this->_object == nullptr) return nullptr;

            return _object; 
        }

        T* get() {
            // Check if our object is existent
            if (_object == nullptr) return nullptr;

            return _object;
        }

        /**
         * @brief Release ownership of stored pointer
         * 
         * @return T* 
         */
        T* release() {
            if (_object == nullptr) return nullptr;

            this->_object = nullptr;

            return _object;
        }

        void reset(T* _new_pointer = T()) noexcept {
            // need to delete current pointer and replace with new
            _deleter(_object);
            this->_object = _new_pointer;
        }

        bool operator == (T* _other_pointer) noexcept {
            return this->_object == _other_pointer;
        }

        ~unique_pointer() {
            printf("In unique pointer dtor\n");
            if (this->_object != nullptr) {
                _deleter(_object);
            }
        }


        private:

        T* _object;
        deleter _deleter;


    };

    template <typename T, typename ..._Args>
    speck::unique_pointer<T> make_unique(_Args... __args) {
        // return constructor of unique pointer
        return speck::unique_pointer<T>(new T(std::forward<_Args>(__args)...));
    }


}


#endif