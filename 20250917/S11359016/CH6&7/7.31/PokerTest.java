public class PokerTest{
    public static void main(String[] args){
        DeckOfCards deck = new DeckOfCards();
        deck.shuffle();

        Card[] hand1 = deck.dealHand(5);
        Card[] hand2 = deck.dealHand(5);

        System.out.println("Hand 1:");
        printHand(hand1);
        String rank1 = evaluate(hand1);
        System.out.println(" → " + rank1 + "\n");

        System.out.println("Hand 2:");
        printHand(hand2);
        String rank2 = evaluate(hand2);
        System.out.println(" → " + rank2 + "\n");

        int result = compare(hand1, hand2);
        if(result > 0)
            System.out.println("Hand 1 wins!");
        else if(result < 0)
            System.out.println("Hand 2 wins!");
        else
            System.out.println("It's a tie!");
    }

    private static void printHand(Card[] hand){
        for(Card c : hand)
            System.out.println("  " + c);
    }

    private static String evaluate(Card[] hand){
        if(DeckOfCards.isStraight(hand) && DeckOfCards.isFlush(hand))
            return "Straight Flush";
        else if(DeckOfCards.isFourOfAKind(hand))
            return "Four of a Kind";
        else if(DeckOfCards.isFullHouse(hand))
            return "Full House";
        else if(DeckOfCards.isFlush(hand))
            return "Flush";
        else if(DeckOfCards.isStraight(hand))
            return "Straight";
        else if(DeckOfCards.isThreeOfAKind(hand))
            return "Three of a Kind";
        else if(DeckOfCards.isTwoPair(hand))
            return "Two Pair";
        else if(DeckOfCards.isPair(hand))
            return "One Pair";
        else
            return "High Card";
    }

    private static int compare(Card[] h1, Card[] h2){
        int r1 = rankValue(h1);
        int r2 = rankValue(h2);
        return Integer.compare(r1, r2);
    }

    private static int rankValue(Card[] hand){
        if(DeckOfCards.isStraight(hand) && DeckOfCards.isFlush(hand)) return 9;
        if(DeckOfCards.isFourOfAKind(hand)) return 8;
        if(DeckOfCards.isFullHouse(hand)) return 7;
        if(DeckOfCards.isFlush(hand)) return 6;
        if(DeckOfCards.isStraight(hand)) return 5;
        if(DeckOfCards.isThreeOfAKind(hand)) return 4;
        if(DeckOfCards.isTwoPair(hand)) return 3;
        if(DeckOfCards.isPair(hand)) return 2;
        return 1;
    }
}