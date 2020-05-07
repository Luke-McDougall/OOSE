public class BaseArmour extends Item implements Armour
{
    private String material;

    public BaseArmour(String name, int value, int effectMin, int effectMax, String material)
    {
        super(name, value, effectMin, effectMax);
        this.material = material;
    }
}
