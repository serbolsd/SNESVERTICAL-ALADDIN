/**
 * @LC	   : 22/10/2019
 * @file   : Animator.h
 * @Author : Roberto Charreton (idv17c.rcharreton@uartesdigitales.edu.mx)
 * @date   : 22/10/2019
 * @brief  : Class in charge of manging the animations of an object.
 * @bug	   : No known bugs.
 */

/**
 * Headers
 */
#include <vector>
#include <string>
#include "../include/Animation.h"
#include "component.h"
#include "GameObject.h"
 /**
 * @brief : Descriptor for the animator initialization. 
 */
struct AnimatorDesc
{
  // Texture path.
  std::string walkPath;
  // Texture dimension for animation.
  sf::Vector2u walkProportion;
  std::string RunPath;
  sf::Vector2u runProportion;
  std::string AttackPath;
  sf::Vector2u attackProportion;
  std::string JumpPath;
  sf::Vector2u jumpProportion;
  std::string DiePath;
  sf::Vector2u dieProportion;
  std::string IdlePath;
  sf::Vector2u idleProportion;
  std::string SwingPath;
  sf::Vector2u swingProportion;
};

/**
 * @brief : Class in charge of manging the animations of an object.
 */
class Animator : public Component
{
public:
  Animator();
  ~Animator();

  /**
   * Members 
   */
private:
  /**
   * @brief : Animation Object.
   */
  Animation m_animation;
  /**
   * @brief : Reference to the player's texture.
   */
  sf::Texture m_playerTexture;

  /**
   * Methods 
   */
public:
  /**
    * @brief  : Function that initialize the animation.
    * @param  : PathsDesc _pathsDesc : Descriptor of the animator.
                sf::CircleShape & _Player : Player object.
                unsigned int _animID : Identifier for state of the animator
    * @bug    : No known bugs.
    */
  Animation
  Init(AnimatorDesc _pathsDesc, sf::RectangleShape * _Player, unsigned int _animID);
  /**
    * @brief  : Function in charge of updating the animation.
    * @param  : sf::CircleShape & _Player : 
                int row : Row of the animation position.
                float deltaTime : Current time for playing the animation.
                bool isFaceRight : Flip the image on runtime;
    * @bug    : No known bugs.
    */
  void 
  update();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  Animation
  changeAnim();
  /**
	* @brief  :
	* @param  :
	* @bug    : No known bugs.
	*/
  void 
  Render();
  /**
    * @brief  : 
    * @param  : 
    * @bug    : No known bugs.
    */
  void 
  Destroy();
  /**
    * @brief  : Function that gets the Animation object.
    * @bug    : No know bugs.
    */
  Animation & getAnimation();
  AnimatorDesc pathsDesc;
  sf::RectangleShape * Player; 
  unsigned int animID;
};

