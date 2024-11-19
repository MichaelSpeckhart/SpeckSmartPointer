#pragma once

#ifndef UNIQUE_POINTER_H
#define UNIQUE_POINTER_H

#include <memory>
#include <atomic>
#include <type_traits>


namespace speck {


    struct default_deleter {

    };


    template <typename T> class unique_pointer {
        public:

        /**
         * @brief Construct a new unique pointer object
         * 
         * @param object 
         */
        explicit unique_pointer(T* object = nullptr) noexcept : _object(object) { }

        /**
         * @brief Construct a new unique pointer object using copy semantics
         * 
         * @param copy_pointer 
         */
        explicit unique_pointer(speck::unique_pointer<T>&& copy_pointer) noexcept : _object(copy_pointer._object) {
            //this = std::move(_copy_pointer);
            copy_pointer._object = nullptr;
        }

        T& operator * () { return *_object;  }

        T* operator -> () { return _object; }

        T* get() {
            // Check if our object is existent
            if (_object == nullptr) return nullptr;

            return _object;
        }

        T* release() {
            if (_object == nullptr) return nullptr;

            this->_object = nullptr;

            return _object;
        }

        void reset(T* _pointer = T()) noexcept {
            // need to delete current pointer and replace with new
        }


        private:

        T* _object;


    };

    template <typename T, typename ..._Args>
    speck::unique_pointer<T> make_unique(_Args... __args) {
        // return constructor of unique pointer
        return speck::unique_pointer<T>(new T(std::forward<_Args>(__args)...));
    }


}


#endif