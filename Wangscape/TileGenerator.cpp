#include "TileGenerator.h"
#include "TilePartition.h"



TileGenerator::TileGenerator()
{
}


TileGenerator::~TileGenerator()
{
}

void TileGenerator::generate(sf::RenderTexture& image, size_t x, size_t y,
                             std::vector<Options::TerrainID> corners,
                             const TerrainImages& images,
                             const Options& options)
{
    const TilePartition tp(corners, options.resolution);
    sf::RenderTexture temp;
    temp.create(options.resolution, options.resolution);
    for (auto it : tp.regions)
    {
        sf::Sprite tex(images.terrain_textures.at(it.second));
        temp.draw(tex, sf::RenderStates(sf::BlendNone));
        sf::Sprite mask(it.first);
        temp.draw(mask, sf::RenderStates(sf::BlendMultiply));
        temp.display();
        sf::Sprite tile(temp.getTexture());
        tile.setPosition(sf::Vector2f((float)x, (float)y)*(float)options.resolution);
        image.draw(tile);
    }
}
