/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <vector>
#include <boost/serialization/access.hpp>
#include <boost/serialization/vector.hpp>

#define NB_CHANNELS 2
#define SAMPLE_RATE 48000
#define FRAMES_PER_BUFFER 480
#define PA_SAMPLE_TYPE paFloat32

class Sound {
    public:
        class Encoded {
            friend class boost::serialization::access;
            template<class Archive>
            void serialize(Archive &ar, const unsigned int version) {
                ar & buffer;
                ar & size;
            }
            public:
                std::vector<unsigned char> buffer;
                int	size;
        };

        class Decoded {
            friend class boost::serialization::access;
            template<class Archive>
            void serialize(Archive &ar, const unsigned int version){
                ar & buffer;
                ar & size;
            }
            public:
                std::vector<float> buffer;
                int	size;
        };
};

#endif /* !SOUND_HPP_ */
